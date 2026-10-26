
undefined4 FUN_004b2730(int param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint local_2c;
  uint local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936d4e;
  local_14 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    local_2c = 0;
  }
  else {
    local_2c = (param_2 - 2) / 0xc;
  }
  if (local_2c != 0) {
    puVar5 = (undefined4 *)(param_1 + 4);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 0;
        FUN_004dec90(uVar4);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_28 = (uint)*(ushort *)((int)puVar5 + -2);
      FUN_0082ef00(&local_28);
      if ((local_24 != DAT_00fab13c) && (iVar3 = *(int *)(local_24 + 0x10), iVar3 != 0)) {
        bVar1 = *(byte *)(iVar3 + 0xb0);
        local_20 = 0;
        *(undefined4 *)(iVar3 + 0xd8) = 0;
        local_1c = 0;
        *(undefined4 *)(iVar3 + 0xdc) = 0;
        uVar2 = *(ushort *)(puVar5 + 2);
        *(undefined4 *)(iVar3 + 0xc0) = *puVar5;
        *(undefined4 *)(iVar3 + 0xc4) = puVar5[1];
        *(uint *)(iVar3 + 200) = (uint)uVar2;
        *(undefined4 *)(iVar3 + 0xd4) = 1;
        *(undefined4 *)(iVar3 + 0xe8) = *puVar5;
        *(undefined4 *)(iVar3 + 0xec) = puVar5[1];
        if ((*(int *)(iVar3 + 0x3a8) == 0) &&
           ((*(byte *)(iVar3 + 0x3a4) = bVar1, *(int *)(iVar3 + 0x370) != 0 &&
            (iVar3 = *(int *)(iVar3 + 0x15c), iVar3 != 0)))) {
          if ((DAT_00fb7c18 & 1) == 0) {
            DAT_00fb7c18 = DAT_00fb7c18 | 1;
            FUN_004449d0();
          }
          (**(code **)(*(int *)(iVar3 + 4) + 0xc))((&DAT_00fb7c20)[bVar1]);
        }
      }
      puVar5 = puVar5 + 3;
      local_2c = local_2c - 1;
    } while (local_2c != 0);
  }
  ExceptionList = local_14;
  return 0;
}

