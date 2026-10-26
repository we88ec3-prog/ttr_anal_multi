
undefined2 FUN_00549320(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  int *piVar7;
  float fVar8;
  float local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_24 = *(float *)(param_1 + 0x78 + *(int *)(param_1 + 0x10c) * 0x10);
  uVar1 = 0;
  if (local_24 != 0.0) {
    fVar8 = local_24;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    piVar4 = DAT_00fab13c;
    local_c = 0xffffffff;
    piVar7 = (int *)*DAT_00fab13c;
    if (piVar7 != DAT_00fab13c) {
      do {
        iVar2 = piVar7[4];
        cVar6 = (char)*(undefined2 *)(iVar2 + 4);
        if (((((cVar6 == '\x01') || (cVar6 == '\0')) && (cVar6 = FUN_004c96b0(iVar2), cVar6 != '\0')
             ) && ((*(int *)(iVar2 + 0x158) != 0 && (*(int *)(*(int *)(iVar2 + 0x158) + 0x34) == 0))
                  )) && (FUN_00549290(), fVar8 < local_24)) {
          uVar1 = *(undefined2 *)(iVar2 + 4);
          local_24 = fVar8;
        }
        if (*(char *)((int)piVar7 + 0x15) == '\0') {
          piVar3 = (int *)piVar7[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar6 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar6 == '\0') {
              cVar6 = *(char *)(*piVar3 + 0x15);
              piVar7 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar6 = *(char *)(piVar7[1] + 0x15);
            piVar5 = (int *)piVar7[1];
            piVar3 = piVar7;
            while ((piVar7 = piVar5, cVar6 == '\0' && (piVar3 == (int *)piVar7[2]))) {
              cVar6 = *(char *)(piVar7[1] + 0x15);
              piVar5 = (int *)piVar7[1];
              piVar3 = piVar7;
            }
          }
        }
      } while (piVar7 != piVar4);
      ExceptionList = local_14;
      return uVar1;
    }
  }
  ExceptionList = local_14;
  return 0;
}

