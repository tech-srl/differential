typedef int PRInt32;
typedef char PRUnichar;
typedef int nsresult;
#define NS_ERROR_DOM_DOMSTRING_SIZE_ERR -1;
extern void * memcpy(PRUnichar *, PRUnichar *, PRInt32);

nsresult SetTextInternal (int textLength, int aCount, int aLength, int aOffset, PRUnichar * aBuffer) {
  PRInt32 newLength = textLength - aCount + aLength ;
  PRUnichar * to;

  memcpy (to + aOffset , aBuffer , aLength * sizeof ( PRUnichar ));
  
  return 0;
}

