
undefined4 FUN_00712aa0(uint param_1)

{
  uint uVar1;
  int *in_EAX;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  if ((*in_EAX == 0xb) &&
     (uVar1 = *(uint *)(*(int *)(*in_ECX + 0xc) + in_EAX[2] * 4), ((byte)uVar1 & 0x3f) == 0x13)) {
    in_ECX[6] = in_ECX[6] + -1;
    uVar2 = FUN_00711ce0(0x1a,uVar1 >> 0x17,param_1 == 0);
    return uVar2;
  }
  if (*in_EAX != 0xc) {
    iVar3 = in_ECX[9] + 1;
    if ((int)(uint)*(byte *)(*in_ECX + 0x4b) < iVar3) {
      if (0xf9 < iVar3) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(in_ECX[3],"function or expression too complex",
                     *(undefined4 *)(in_ECX[3] + 0x10));
      }
      *(char *)(*in_ECX + 0x4b) = (char)iVar3;
    }
    in_ECX[9] = in_ECX[9] + 1;
    FUN_00712360(in_ECX[9] + -1);
    if (*in_EAX != 0xc) goto LAB_00712b4d;
  }
  if (((in_EAX[2] & 0x100U) == 0) && ((int)(uint)*(byte *)((int)in_ECX + 0x32) <= in_EAX[2])) {
    in_ECX[9] = in_ECX[9] + -1;
  }
LAB_00712b4d:
  FUN_00713370((in_EAX[2] << 9 | param_1) << 0xe | 0x3fdb,*(undefined4 *)(in_ECX[3] + 8));
  in_ECX[8] = -1;
  uVar2 = FUN_00713370(0x7fff8016,*(undefined4 *)(in_ECX[3] + 8));
  FUN_00711fe0();
  return uVar2;
}

