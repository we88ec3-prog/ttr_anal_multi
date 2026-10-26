
void FUN_006a93e0(void)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  short *psVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  ushort ****ppppuVar8;
  ushort ****ppppuVar9;
  undefined1 *puVar10;
  int *piVar11;
  undefined2 auStack_f4 [8];
  undefined4 uStack_e4;
  undefined2 *puStack_e0;
  undefined2 auStack_d8 [8];
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  ushort ***pppuStack_c0;
  ushort ***pppuStack_bc;
  undefined1 auStack_a4 [4];
  undefined4 local_a0;
  undefined1 *puStack_9c;
  ushort ***local_98;
  ushort ***local_94;
  undefined1 *puStack_90;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  ushort ***local_54 [5];
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942870;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_a4;
  ExceptionList = &local_14;
  pppuStack_bc = (ushort ***)0x6a942c;
  FUN_00757200();
  local_c = 0;
  pppuStack_bc = (ushort ***)0x6a9445;
  FUN_00765bc0();
  psVar4 = (short *)&local_a0;
  local_a0 = 0x2019;
  local_5c = 7;
  local_60 = 0;
  local_70 = (uint)local_70._2_2_ << 0x10;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  pppuStack_bc = (ushort ***)&local_a0;
  pppuStack_c0 = (ushort ***)0x6a948e;
  FUN_00402160();
  local_c._0_1_ = 1;
  pppuStack_bc = (ushort ***)&DAT_00c34b58;
  local_78 = 7;
  local_7c = 0;
  local_8c = (ushort ***)((uint)local_8c._2_2_ << 0x10);
  pppuStack_c0 = (ushort ***)0x6a94b5;
  FUN_00402160();
  pppuStack_bc = (ushort ***)&local_8c;
  pppuStack_c0 = (ushort ***)local_54;
  local_c = CONCAT31(local_c._1_3_,2);
  uStack_c4 = 0x6a94d1;
  FUN_00759330();
  if (7 < local_78) {
    pppuStack_bc = (ushort ***)0x6a94e6;
    FUN_0089120c();
  }
  local_c = local_c & 0xffffff00;
  local_78 = 7;
  local_7c = 0;
  local_8c = (ushort ***)((uint)local_8c & 0xffff0000);
  if (7 < local_5c) {
    pppuStack_bc = (ushort ***)0x6a950f;
    FUN_0089120c();
  }
  if (local_40 < 8) {
    ppppuVar9 = local_54;
    local_94 = (ushort ***)ppppuVar9;
  }
  else {
    local_94 = local_54[0];
    ppppuVar9 = (ushort ****)local_54[0];
  }
  local_94 = (ushort ***)ppppuVar9;
  if ((DAT_00fb75c0 & 1) == 0) {
    DAT_00fb75c0 = DAT_00fb75c0 | 1;
    local_c._0_1_ = 3;
    FUN_0081e5f0();
    pppuStack_bc = (ushort ***)0x6a9553;
    _atexit((_func_4879 *)&LAB_00bcd250);
    local_c = (uint)local_c._1_3_ << 8;
  }
  if (ppppuVar9 != (ushort ****)0x0) {
    local_98 = (ushort ***)ppppuVar9;
    uVar2 = *(ushort *)ppppuVar9;
    piVar11 = DAT_00fb7608;
    while (uVar2 != 0) {
      puVar10 = (undefined1 *)(uint)*(ushort *)local_98;
      if (*(ushort *)local_98 < 0x80) {
        if ((((((undefined1 *)0x9 < puVar10 + -0x30) && ((undefined1 *)0x19 < puVar10 + -0x41)) &&
             ((undefined1 *)0x19 < puVar10 + -0x61)) &&
            ((puVar10 != (undefined1 *)0x20 && (puVar10 != (undefined1 *)0xd)))) &&
           ((puVar10 != (undefined1 *)0xa && ((undefined1 *)0x5d < puVar10 + -0x21))))
        goto LAB_006a96e9;
      }
      else {
        pppuStack_bc = (ushort ***)0x6a959b;
        iVar5 = (**(code **)(*piVar11 + 8))();
        piVar11 = DAT_00fb7608;
        iVar7 = DAT_00fb7608[2];
        pppuStack_bc = (ushort ***)0x6a95bd;
        puStack_9c = puVar10;
        piVar6 = (int *)FUN_0081ed70();
        ppppuVar9 = (ushort ****)local_94;
        if ((*piVar6 == iVar7) && (iVar5 == 0)) goto LAB_006a96e9;
      }
      local_98 = (ushort ***)((int)local_98 + 2);
      uVar2 = *(ushort *)local_98;
    }
    pppuStack_c0 = (ushort ***)&DAT_00fb75c8;
    uStack_c4 = 0x6a95ef;
    pppuStack_bc = (ushort ***)ppppuVar9;
    iVar7 = FUN_0081eb80();
    if (iVar7 == 0) {
      pppuStack_c0 = (ushort ***)&DAT_00fb75f8;
      uStack_c4 = 0x6a9608;
      pppuStack_bc = (ushort ***)ppppuVar9;
      iVar7 = FUN_0081eb80();
      if (iVar7 == 0) {
        if ((DAT_00fbad10 & 1) == 0) {
          DAT_00fbad10 = DAT_00fbad10 | 1;
          local_c._0_1_ = 7;
          FUN_004e8010();
          pppuStack_bc = (ushort ***)0x6a964a;
          _atexit((_func_4879 *)&LAB_00bcd6b0);
          local_c = (uint)local_c._1_3_ << 8;
        }
        FUN_004ecef0();
        goto LAB_006a9666;
      }
    }
  }
LAB_006a96e9:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c._0_1_ = 4;
    FUN_00587480();
    pppuStack_bc = (ushort ***)0x6a9710;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = (uint)local_c._1_3_ << 8;
  }
  pppuStack_bc = (ushort ***)0x0;
  puStack_90 = (undefined1 *)auStack_d8;
  uStack_c4 = 7;
  uStack_c8 = 0;
  puStack_e0 = &DAT_00bed1fc;
  auStack_d8[0] = 0;
  uStack_e4 = 0x6a9740;
  FUN_00402160();
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 6;
    puStack_e0 = (undefined2 *)0x6a976b;
    FUN_00584c40();
    puStack_e0 = (undefined2 *)0x6a9775;
    _atexit(FUN_00bcf370);
  }
  local_c._0_1_ = 5;
  puStack_9c = (undefined1 *)0x72;
  puStack_e0 = (undefined2 *)0x6a979a;
  FUN_005740f0();
  if ((ushort ****)local_98 == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  ppppuVar9 = (ushort ****)(local_98 + 4);
  if ((ushort ***)0x7 < local_98[9]) {
    ppppuVar9 = (ushort ****)*ppppuVar9;
  }
  puStack_9c = (undefined1 *)auStack_f4;
  uStack_e4 = 0;
  puStack_e0 = (undefined2 *)0x7;
  auStack_f4[0] = 0;
  ppppuVar8 = ppppuVar9;
  do {
    uVar2 = *(ushort *)ppppuVar8;
    ppppuVar8 = (ushort ****)((int)ppppuVar8 + 2);
  } while (uVar2 != 0);
  FUN_00402160(ppppuVar9,(int)ppppuVar8 - (int)((int)ppppuVar9 + 2) >> 1);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_0058b270(0xca);
LAB_006a9666:
  local_c = 0xffffffff;
  pppuStack_bc = (ushort ***)0x6a9676;
  FUN_00757640();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_a4);
  return;
}

