/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsArrayEnumerator_h__
#define nsArrayEnumerator_h__

// enumerator implementation for nsIArray

#include "nscore.h"

class nsISimpleEnumerator;
class nsIArray;
class nsCOMArray_base;

// Create an enumerator for an existing nsIArray implementation
// The enumerator holds an owning reference to the array.
NS_COM_GLUE nsresult
NS_NewArrayEnumerator(nsISimpleEnumerator* *result NS_OUTPARAM,
                      nsIArray* array);

// create an enumerator for an existing nsCOMArray<T> implementation
// The enumerator will hold an owning reference to each ELEMENT in
// the array. This means that the nsCOMArray<T> can safely go away
// without its objects going away.
NS_COM_GLUE nsresult
NS_NewArrayEnumerator(nsISimpleEnumerator* *aResult NS_OUTPARAM,
                      const nsCOMArray_base& aArray);

#endif
