
void FUN_00712030(void)

{
  int iVar1;
  int *in_ECX;
  int unaff_ESI;
  
  iVar1 = in_ECX[9] + unaff_ESI;
  if ((int)(uint)*(byte *)(*in_ECX + 0x4b) < iVar1) {
    if (0xf9 < iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(in_ECX[3],"function or expression too complex",*(undefined4 *)(in_ECX[3] + 0x10))
      ;
    }
    *(char *)(*in_ECX + 0x4b) = (char)iVar1;
  }
  in_ECX[9] = in_ECX[9] + unaff_ESI;
  return;
}

