
void FUN_007556c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  float local_20;
  float local_1c;
  undefined4 local_18;
  float local_14;
  float local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = *(int *)(in_ECX + 0x24);
  if (iVar1 != 0) {
    param_1 = param_5 + param_1;
    param_2 = param_6 + param_2;
    param_6 = param_6 - *(int *)(in_ECX + 0x30);
    iVar2 = param_5 - *(int *)(in_ECX + 0x2c);
    param_7 = param_7 - *(int *)(in_ECX + 0x2c);
    param_8 = param_8 - *(int *)(in_ECX + 0x30);
    param_5 = iVar2;
    if ((*(uint *)(in_ECX + 0x28) >> 0xe & 1) != 0) {
      local_20 = (float)param_1;
      local_1c = (float)param_2;
      FUN_00751520(*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),
                   *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc),&local_20,&param_3,
                   *(undefined4 *)(in_ECX + 0x80));
      FUN_00751800();
      return;
    }
    local_8 = param_8 - param_6;
    local_10 = (float)(param_7 - iVar2);
    local_c = *(undefined4 *)(iVar1 + 8);
    local_1c = (float)FUN_008fed10();
    local_18 = FUN_008fed10();
    FUN_00755370(local_c,*(undefined4 *)(iVar1 + 0xc),local_10,local_8,-iVar2,-param_6);
    local_14 = (float)param_1;
    local_10 = (float)param_2;
    FUN_00751520(local_1c,local_18,&local_14,&param_3,*(undefined4 *)(in_ECX + 0x80));
    FUN_00751800();
  }
  return;
}

