
undefined4 FUN_004b01c0(int param_1,uint param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  uint local_24;
  uint local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947dca;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    local_24 = 0;
  }
  else {
    local_24 = (param_2 - 2) / 9;
  }
  if (local_24 != 0) {
    psVar5 = (short *)(param_1 + 5);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar4);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_20 = (uint)*(ushort *)((int)psVar5 + -3);
      FUN_0082ef00(&local_20);
      if ((local_1c == DAT_00fab13c) || (piVar2 = *(int **)(local_1c + 0x10), piVar2 == (int *)0x0))
      {
        FUN_006edb60("Error [USE_SKILL]: cannot found In CharList");
      }
      else {
        (**(code **)(*piVar2 + 0x58))(*(undefined1 *)((int)psVar5 + -1));
        if (piVar2[0xea] != 0) {
          piVar2[0xea] = 0;
        }
        bVar1 = *(byte *)(piVar2 + 0x2c);
        if (((piVar2[0xea] == 0) && (*(byte *)(piVar2 + 0xe9) = bVar1, piVar2[0xdc] != 0)) &&
           (iVar3 = piVar2[0x57], iVar3 != 0)) {
          if ((DAT_00fb7c18 & 1) == 0) {
            DAT_00fb7c18 = DAT_00fb7c18 | 1;
            FUN_004449d0();
          }
          local_20 = (&DAT_00fb7c20)[bVar1];
          (**(code **)(*(int *)(iVar3 + 4) + 0xc))(local_20);
        }
        FUN_004c8a90(*psVar5,*(undefined4 *)(psVar5 + 1));
        iVar3 = piVar2[0x27];
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 1;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if ((iVar3 == DAT_00f93930) && (*psVar5 == 0x12)) {
          if ((DAT_00fab29c & 1) == 0) {
            DAT_00fab29c = DAT_00fab29c | 1;
            local_c = 2;
            FUN_004ffe60();
            _atexit((_func_4879 *)&LAB_00bccf00);
            local_c = 0xffffffff;
          }
          FUN_00501650(10);
        }
      }
      psVar5 = (short *)((int)psVar5 + 9);
      local_24 = local_24 - 1;
    } while (local_24 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

