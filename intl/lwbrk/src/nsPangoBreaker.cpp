/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsComplexBreaker.h"

#include <pango/pango-break.h>
#include "nsUTF8Utils.h"
#include "nsString.h"
#include "nsTArray.h"

void
NS_GetComplexLineBreaks(const PRUnichar* aText, PRUint32 aLength,
                        PRUint8* aBreakBefore)
{
  NS_ASSERTION(aText, "aText shouldn't be null");

  memset(aBreakBefore, false, aLength * sizeof(PRUint8));

  nsAutoTArray<PangoLogAttr, 2000> attrBuffer;
  if (!attrBuffer.AppendElements(aLength + 1))
    return;

  NS_ConvertUTF16toUTF8 aUTF8(aText, aLength);

  const gchar* p = aUTF8.Data();
  const gchar* end = p + aUTF8.Length();
  PRUint32     u16Offset = 0;

  static PangoLanguage* language = pango_language_from_string("en");

  while (p < end)
  {
    PangoLogAttr* attr = attrBuffer.Elements();
    pango_get_log_attrs(p, end - p, -1, language, attr, attrBuffer.Length());

    while (p < end)
    {
      aBreakBefore[u16Offset] = attr->is_line_break;
      if (NS_IS_LOW_SURROGATE(aText[u16Offset]))
        aBreakBefore[++u16Offset] = false; // Skip high surrogate
      ++u16Offset;

      bool err;
      PRUint32 ch = UTF8CharEnumerator::NextChar(&p, end, &err);
      ++attr;

      if (ch == 0 || err) {
        // pango_break (pango 1.16.2) only analyses text before the
        // first NUL (but sets one extra attr). Workaround loop to call
        // pango_break again to analyse after the NUL is done somewhere else
        // (gfx/thebes/gfxPangoFonts.cpp: SetupClusterBoundaries()).
        // So, we do the same here for pango_get_log_attrs.
        break;
      }
    }
  }
}
