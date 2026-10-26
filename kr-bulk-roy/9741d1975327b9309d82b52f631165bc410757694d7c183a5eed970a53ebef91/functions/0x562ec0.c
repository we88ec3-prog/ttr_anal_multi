
void FUN_00562ec0(undefined1 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,int param_7,int param_8,uint param_9)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int unaff_EDI;
  int iVar10;
  uint uStack_44;
  void *pvStack_34;
  undefined2 local_30;
  undefined4 uStack_24;
  int local_20;
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  uVar7 = param_2;
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093a103;
  local_14 = ExceptionList;
  uStack_44 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  if ((int)param_2 < 10) {
    local_30._0_1_ = 0;
  }
  else if ((int)param_2 < 10000) {
    local_30._0_1_ = 1;
  }
  else if ((int)param_2 < 11000) {
    local_30._0_1_ = 6;
  }
  else if ((int)param_2 < 21000) {
    local_30._0_1_ = 7;
  }
  else {
    FUN_006edb60(&DAT_00c10718,param_2);
    local_30._0_1_ = 0;
  }
  local_30 = CONCAT11(param_1,(byte)local_30);
  local_20 = FUN_00891268(0x438);
  piVar9 = (int *)0x0;
  local_c = 0;
  if (local_20 != 0) {
    piVar9 = (int *)FUN_004d0b80(local_20);
  }
  local_c = 0xffffffff;
  *(undefined2 *)(piVar9 + 1) = local_30;
  pcVar1 = *(code **)(*piVar9 + 0x3c);
  piVar9[0x24] = 0x10;
  (*pcVar1)((uint)(byte)local_30 << 0x18 | uVar7 & 0xffff);
  iVar10 = 1;
  uStack_24 = param_3;
  local_20 = param_4;
  (**(code **)(*piVar9 + 0x44))(&uStack_24,1);
  (**(code **)(*piVar9 + 0x58))(param_5);
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    uStack_1c = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    uStack_1c = 0xffffffff;
  }
  iVar5 = FUN_004f7a70();
  iVar5 = *(int *)(iVar5 + 0x5c);
  (**(code **)(*piVar9 + 0x5c))(iVar5);
  iVar8 = param_8;
  if (((int)uVar7 < 10) && (param_8 == 0)) {
    iVar8 = 1;
  }
  *(short *)(piVar9 + 0xe2) = (short)iVar8;
  if ((piVar9[0x57] != 0) && (piVar9[0xdc] != 0)) {
    FUN_007a6ea0(piVar9[0x57],1,iVar8);
  }
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_20 = 2;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    local_20 = 0xffffffff;
  }
  FUN_00515790(&stack0xffffffc4);
  if ((uStack_44 == DAT_00fc0e94) || (*(int *)(*(int *)(uStack_44 + 0x10) + 0x54) == 0)) {
    uVar6 = FUN_006bde40(&param_2);
    FUN_0044bbd0(unaff_EDI + 0x60,uVar6);
    if ((DAT_00fc0e40 & 1) == 0) {
      DAT_00fc0e40 = DAT_00fc0e40 | 1;
      local_20 = 3;
      FUN_00540770();
      _atexit((_func_4879 *)&LAB_00bcdb60);
      local_20 = 0xffffffff;
    }
    FUN_00541610(uVar7);
  }
  if (*(int *)(unaff_EDI + 0x70) != 0) {
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_20 = 4;
      FUN_0079cf40();
      _atexit((_func_4879 *)&LAB_00bcdb80);
      local_20 = 0xffffffff;
    }
    FUN_00515790(&stack0xffffffc4);
    if ((uStack_44 != DAT_00fc0e94) &&
       (iVar8 = *(int *)(*(int *)(uStack_44 + 0x10) + 0x54), iVar8 != 0)) {
      FUN_007c57f0(1);
      FUN_007c57f0(4);
      iVar2 = *(int *)(unaff_EDI + 0x70);
      FUN_00826280(&stack0xffffffc4);
      if (uStack_44 != *(uint *)(iVar2 + 4)) {
        pvStack_34 = *(void **)(uStack_44 + 0x10);
        piVar3 = *(int **)((int)pvStack_34 + 8);
        piVar4 = (int *)*piVar3;
        while (piVar4 != piVar3) {
          uStack_44 = (uint)*(ushort *)(piVar4 + 3);
          FUN_0082ef00(&uStack_44);
          if ((iVar5 != *(int *)(iVar8 + 0xd8)) &&
             (uVar7 = (**(code **)(**(int **)(iVar5 + 0x10) + 8))(), uVar7 == uStack_44)) {
            (**(code **)(**(int **)(iVar5 + 0x10) + 0x24))();
          }
          FUN_0081d850();
          piVar3 = *(int **)((int)pvStack_34 + 8);
        }
      }
    }
  }
  FUN_004d0fe0();
  (**(code **)(piVar9[0x3c] + 8))(0x14);
  (**(code **)(*piVar9 + 0x68))(param_6,0x3f800000);
  if (((param_9 != 0) && (piVar9[0x57] != 0)) && (piVar9[0xdc] != 0)) {
    FUN_007a7240(piVar9[0x57],param_9 & 0xffff,0,0);
  }
  piVar9[0x10b] = param_7;
  uVar6 = FUN_0057ef20();
  FUN_0082f200(iVar10 + 0x18,uVar6);
  ExceptionList = pvStack_34;
  return;
}

