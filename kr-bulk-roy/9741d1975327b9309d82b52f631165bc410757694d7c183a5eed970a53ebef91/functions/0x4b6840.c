
undefined4 FUN_004b6840(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00947bc6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(param_1 + 10) == 0x1471) && (*(char *)(param_1 + 0xe) == '\0')) {
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 0;
      FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccf00);
    }
    local_8 = 0xffffffff;
    FUN_00501650(0x16);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  iVar3 = FUN_0051d700(*(undefined4 *)(param_1 + 10));
  if (iVar3 != 0) {
    iVar4 = *(int *)(iVar3 + 0x148);
    uVar5 = 0;
    if (*(int *)(iVar3 + 0x14c) - iVar4 >> 2 != 0) {
      do {
        sVar2 = *(short *)(*(int *)(iVar4 + uVar5 * 4) + 8);
        if (sVar2 == 0x12) {
          if ((DAT_00faadd4 & 1) == 0) {
            DAT_00faadd4 = DAT_00faadd4 | 1;
            local_8 = 3;
            FUN_00587480();
            _atexit((_func_4879 *)&LAB_00bcccc0);
            local_8 = 0xffffffff;
          }
          cVar1 = *(char *)(param_1 + 0xe);
          uVar7 = *(undefined4 *)(param_1 + 10);
          uVar6 = 0xf42a9;
LAB_004b69a4:
          FUN_0058ac30(uVar6,uVar7,(int)cVar1);
        }
        else if (sVar2 == 0x18) {
          if ((DAT_00faadd4 & 1) == 0) {
            DAT_00faadd4 = DAT_00faadd4 | 1;
            local_8 = 2;
            FUN_00587480();
            _atexit((_func_4879 *)&LAB_00bcccc0);
            local_8 = 0xffffffff;
          }
          cVar1 = *(char *)(param_1 + 0xe);
          uVar7 = *(undefined4 *)(param_1 + 10);
          uVar6 = 0xf42aa;
          goto LAB_004b69a4;
        }
        iVar4 = *(int *)(iVar3 + 0x148);
        uVar5 = uVar5 + 1;
      } while (uVar5 < (uint)(*(int *)(iVar3 + 0x14c) - iVar4 >> 2));
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 4;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058acf0(0xf42a8,*(undefined4 *)(param_1 + 10),*(char *)(param_1 + 0xe) == '\0',
               (int)*(char *)(param_1 + 0xf));
  ExceptionList = local_10;
  return 0;
}

