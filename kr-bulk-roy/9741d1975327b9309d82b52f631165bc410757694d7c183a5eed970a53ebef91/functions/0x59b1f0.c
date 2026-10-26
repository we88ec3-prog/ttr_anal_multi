
void FUN_0059b1f0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00948ffc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005a4540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*(int *)(in_ECX + 0x164) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x164) + 0x198))();
  }
  if ((*(int *)(in_ECX + 0x170) != 0) &&
     ((*(uint *)(*(int *)(in_ECX + 0x170) + 0x28) >> 8 & 1) != 0)) {
    FUN_0065f5b0();
  }
  iVar2 = *(int *)(in_ECX + 0x18c);
  if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0)) && (*(int *)(iVar2 + 0x80) != 0))
  {
    FUN_0069aac0();
    FUN_004191f0(*(undefined4 *)(iVar2 + 0x84));
  }
  iVar2 = *(int *)(in_ECX + 0x168);
  if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0)) && (*(int *)(iVar2 + 0x118) != -1)
     ) {
    (**(code **)(**(int **)(*(int *)(iVar2 + 0x104) + *(int *)(iVar2 + 0x118) * 4) + 0x1a8))();
  }
  if ((*(int *)(in_ECX + 0x1a4) != 0) &&
     ((*(uint *)(*(int *)(in_ECX + 0x1a4) + 0x28) >> 8 & 1) != 0)) {
    FUN_0063aca0();
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x1d8) + 0x28) >> 8 & 1) != 0) {
    FUN_0060ae70();
  }
  iVar2 = *(int *)(in_ECX + 0x200);
  if ((iVar2 != 0) && ((*(uint *)(iVar2 + 0x28) >> 8 & 1) != 0)) {
    FUN_006cbf40(iVar2);
  }
  if ((*(uint *)(*(int *)(in_ECX + 0x1f0) + 0x28) >> 8 & 1) != 0) {
    FUN_0061a580();
  }
  if ((*(uint *)(*(int *)(in_ECX + 400) + 0x28) >> 8 & 1) != 0) {
    FUN_0069ca70();
  }
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0();
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_8 = 0xffffffff;
  }
  if (DAT_00faaf45 == '\0') goto LAB_0059b3f0;
  cVar1 = FUN_00406700();
  if (cVar1 == '\0') goto LAB_0059b3f0;
  if ((*(uint *)(*(int *)(in_ECX + 0x208) + 0x28) >> 8 & 1) == 0) {
    iVar2 = FUN_00404ba0();
    if (*(int *)(iVar2 + 0x5f4c) != 7) goto LAB_0059b391;
LAB_0059b3ad:
    (**(code **)(**(int **)(in_ECX + 0x208) + 0xd0))();
  }
  else {
LAB_0059b391:
    iVar2 = FUN_00404ba0();
    if (*(int *)(iVar2 + 0x5f4c) == 0x17) goto LAB_0059b3ad;
    iVar2 = FUN_00404ba0();
    if (*(int *)(iVar2 + 0x5f4c) == 0x18) goto LAB_0059b3ad;
  }
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 1;
    FUN_004073c0();
    _atexit((_func_4879 *)&LAB_00bcccd0);
    local_8 = 0xffffffff;
  }
  DAT_00faaf45 = '\0';
LAB_0059b3f0:
  if ((*(uint *)(*(int *)(in_ECX + 0x218) + 0x28) >> 8 & 1) != 0) {
    FUN_004a5870();
  }
  ExceptionList = local_10;
  return;
}

