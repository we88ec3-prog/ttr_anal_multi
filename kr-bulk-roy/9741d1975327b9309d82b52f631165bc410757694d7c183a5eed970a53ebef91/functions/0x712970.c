
void FUN_00712970(int *param_1)

{
  int iVar1;
  uint uVar2;
  int *in_EAX;
  uint uVar3;
  int *in_ECX;
  
  FUN_007122a0();
  if (*in_EAX == 0xc) {
    if (in_EAX[4] == in_EAX[5]) goto LAB_007129b0;
    if ((int)(uint)*(byte *)((int)in_ECX + 0x32) <= in_EAX[2]) {
      FUN_00712510();
      goto LAB_007129b0;
    }
  }
  FUN_00712630();
LAB_007129b0:
  if (((*in_EAX == 0xc) && ((in_EAX[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)((int)in_ECX + 0x32) <= in_EAX[2])) {
    in_ECX[9] = in_ECX[9] + -1;
  }
  uVar2 = in_ECX[9];
  iVar1 = uVar2 + 2;
  if ((int)(uint)*(byte *)(*in_ECX + 0x4b) < iVar1) {
    if (0xf9 < iVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_006ff130(in_ECX[3],"function or expression too complex",*(undefined4 *)(in_ECX[3] + 0x10))
      ;
    }
    *(char *)(*in_ECX + 0x4b) = (char)iVar1;
  }
  in_ECX[9] = in_ECX[9] + 2;
  uVar3 = FUN_00712740();
  FUN_00713370(((in_EAX[2] << 9 | uVar3) << 8 | uVar2) << 6 | 0xb,*(undefined4 *)(in_ECX[3] + 8));
  if (((*param_1 == 0xc) && ((param_1[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)((int)in_ECX + 0x32) <= param_1[2])) {
    in_ECX[9] = in_ECX[9] + -1;
  }
  in_EAX[2] = uVar2;
  *in_EAX = 0xc;
  return;
}

