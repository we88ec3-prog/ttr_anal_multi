
void FUN_00554220(void)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  byte bVar6;
  undefined2 in_FPUControlWord;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  int local_10;
  float local_c;
  undefined4 local_8;
  
  if (((in_EAX[3] != 0) && (in_EAX[2] != 0)) && (DAT_00fe1e40 == 0)) {
    local_20 = 1.0;
    local_1c = 1.0;
    local_18 = 1.0;
    local_14 = 1.0;
    iVar4 = FUN_006dfc40();
    iVar5 = FUN_006dfc40();
    local_20 = (float)*(int *)(iVar4 + 0x18);
    iVar1 = *in_EAX;
    if (*(int *)(iVar4 + 0x18) < 0) {
      local_20 = local_20 + 4.2949673e+09;
    }
    fVar3 = (float)*(int *)(iVar1 + 0xc);
    if (*(int *)(iVar1 + 0xc) < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    local_20 = local_20 / fVar3;
    local_1c = (float)*(int *)(iVar4 + 0x1c);
    if (*(int *)(iVar4 + 0x1c) < 0) {
      local_1c = local_1c + 4.2949673e+09;
    }
    fVar3 = (float)*(int *)(iVar1 + 0x10);
    if (*(int *)(iVar1 + 0x10) < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    local_1c = local_1c / fVar3;
    local_18 = (float)*(int *)(iVar5 + 0x18);
    piVar2 = (int *)in_EAX[1];
    if (*(int *)(iVar5 + 0x18) < 0) {
      local_18 = local_18 + 4.2949673e+09;
    }
    fVar3 = (float)piVar2[3];
    if (piVar2[3] < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    local_18 = local_18 / fVar3;
    local_10 = *(int *)(iVar5 + 0x1c);
    local_14 = (float)local_10;
    if (local_10 < 0) {
      local_14 = local_14 + 4.2949673e+09;
    }
    fVar3 = (float)piVar2[4];
    if (piVar2[4] < 0) {
      fVar3 = fVar3 + 4.2949673e+09;
    }
    local_14 = local_14 / fVar3;
    iVar1 = in_EAX[5];
    bVar6 = 0xff;
    local_8 = local_14;
    if (0xb4 < iVar1) {
      iVar4 = (0xd2 - iVar1) * 0xff;
      local_8._0_2_ = (undefined2)iVar4;
      local_8 = (float)CONCAT22(in_FPUControlWord,(undefined2)local_8);
      local_10 = (int)ROUND((double)iVar4 / 30.0);
      bVar6 = (byte)local_10;
    }
    if (iVar1 < 0x1e) {
      local_8 = (float)CONCAT22(in_FPUControlWord,(undefined2)local_8);
      local_10 = (int)ROUND((double)(iVar1 * 0xff) / 30.0);
      bVar6 = (byte)local_10;
    }
    local_c = local_18;
    if (in_EAX[4] == 0) {
      (**(code **)(*piVar2 + 0x30))(0,0,0,&local_18,(uint)bVar6 << 0x18 | 0xffffff);
    }
    (**(code **)(*(int *)*in_EAX + 0x30))(0,0,0,&local_20,(uint)bVar6 << 0x18 | 0xffffff);
    return;
  }
  in_EAX[4] = 1;
  return;
}

