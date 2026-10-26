
void FUN_00712630(void)

{
  int *in_EAX;
  int iVar1;
  int *in_ECX;
  
  FUN_007122a0();
  if (((*in_EAX == 0xc) && ((in_EAX[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)((int)in_ECX + 0x32) <= in_EAX[2])) {
    in_ECX[9] = in_ECX[9] + -1;
  }
  iVar1 = in_ECX[9] + 1;
  if ((int)(uint)*(byte *)(*in_ECX + 0x4b) < iVar1) {
    if (0xf9 < iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(in_ECX[3],"function or expression too complex",*(undefined4 *)(in_ECX[3] + 0x10))
      ;
    }
    *(char *)(*in_ECX + 0x4b) = (char)iVar1;
  }
  in_ECX[9] = in_ECX[9] + 1;
  FUN_00712510();
  return;
}

