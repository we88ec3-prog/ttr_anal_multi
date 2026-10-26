
void FUN_00474e70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  FUN_00744640(param_1,param_2);
  if ((*(int *)(in_ECX + 0x24) != 0) && (*(int *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x84) != 0)) {
    iVar1 = *(int *)(in_ECX + 8);
    iVar2 = *(int *)(in_ECX + 0x10);
    local_18 = FUN_008fed10();
    iVar3 = *(int *)(in_ECX + 0xc);
    iVar4 = *(int *)(in_ECX + 0x14);
    local_14 = FUN_008fed10();
    local_c = (iVar4 - iVar3) + local_14;
    local_30 = 0x3f800000;
    local_2c = 0x3f800000;
    local_28 = 0x3f800000;
    local_24 = (float)param_1;
    local_10 = (iVar2 - iVar1) + local_18;
    local_20 = (float)param_2;
    local_1c = 0;
    FUN_00750ec0(0x200,0x200,&local_18,&local_24,&local_30);
  }
  return;
}

