
void FUN_00712f90(uint param_1,uint param_2,int *param_3,int *param_4)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = FUN_00712740();
  uVar2 = FUN_00712740();
  if (((*param_4 == 0xc) && ((param_4[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)(in_EAX + 0x32) <= param_4[2])) {
    *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
  }
  if (((*param_3 == 0xc) && ((param_3[2] & 0x100U) == 0)) &&
     ((int)(uint)*(byte *)(in_EAX + 0x32) <= param_3[2])) {
    *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + -1;
  }
  uVar3 = uVar2;
  if ((param_2 == 0) && (param_1 != 0x17)) {
    param_2 = 1;
    uVar3 = uVar1;
    uVar1 = uVar2;
  }
  FUN_00713370(((uVar1 << 9 | uVar3) << 8 | param_2) << 6 | param_1,
               *(undefined4 *)(*(int *)(in_EAX + 0xc) + 8));
  *(undefined4 *)(in_EAX + 0x20) = 0xffffffff;
  iVar4 = FUN_00713370(0x7fff8016,*(undefined4 *)(*(int *)(in_EAX + 0xc) + 8));
  FUN_00711fe0();
  param_3[2] = iVar4;
  *param_3 = 10;
  return;
}

