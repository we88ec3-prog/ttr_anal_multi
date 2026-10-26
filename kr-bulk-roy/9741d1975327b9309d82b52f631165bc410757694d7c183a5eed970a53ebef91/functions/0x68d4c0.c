
void FUN_0068d4c0(int param_1)

{
  ushort uVar1;
  code *pcVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  bool bVar7;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942ba8;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = *(int *)(param_1 + 0xf4);
  if (*(char *)(iVar5 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar3);
  }
  puVar4 = (ushort *)(iVar5 + 0x108);
  if (7 < *(uint *)(iVar5 + 0x11c)) {
    puVar4 = *(ushort **)puVar4;
  }
  puVar6 = &DAT_00bed1fc;
  do {
    uVar1 = *puVar4;
    bVar7 = uVar1 < *puVar6;
    if (uVar1 != *puVar6) {
LAB_0068d546:
      iVar5 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_0068d54b;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar4[1];
    bVar7 = uVar1 < puVar6[1];
    if (uVar1 != puVar6[1]) goto LAB_0068d546;
    puVar4 = puVar4 + 2;
    puVar6 = puVar6 + 2;
  } while (uVar1 != 0);
  iVar5 = 0;
LAB_0068d54b:
  if (iVar5 == 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = iVar5;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_14 = 0x196;
    FUN_005740f0(&local_14);
    if (local_18 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_18 = 0;
    FUN_005740f0(&local_18);
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_14 + 0x24) < 8) {
      iVar5 = local_14 + 0x10;
    }
    else {
      iVar5 = *(int *)(local_14 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar5,0,0);
  }
  if (*(char *)(*(int *)(param_1 + 0xf4) + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",uVar3);
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 3;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_8 = 0xffffffff;
  }
  FUN_0053bb20();
  ExceptionList = local_10;
  return;
}

