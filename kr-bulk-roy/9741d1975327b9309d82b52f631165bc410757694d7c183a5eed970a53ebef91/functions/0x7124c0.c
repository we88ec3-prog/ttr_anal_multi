
void FUN_007124c0(void)

{
  int *in_EAX;
  int *in_ECX;
  int iVar1;
  
  if (*in_EAX != 0xc) {
    iVar1 = in_ECX[9] + 1;
    if ((int)(uint)*(byte *)(*in_ECX + 0x4b) < iVar1) {
      if (0xf9 < iVar1) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(in_ECX[3],"function or expression too complex",
                     *(undefined4 *)(in_ECX[3] + 0x10));
      }
      *(char *)(*in_ECX + 0x4b) = (char)iVar1;
    }
    in_ECX[9] = in_ECX[9] + 1;
    FUN_00712360(in_ECX[9] + -1);
  }
  return;
}

