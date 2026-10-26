
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e0200(int param_1,float param_2)

{
  char cVar1;
  int *piVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined **local_1c;
  float local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009443c4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 0;
    FUN_0079cf40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_8 = 0xffffffff;
  FUN_0079db10();
  (**(code **)(*DAT_00fba838 + 0x18))(param_2);
  local_14 = param_2;
  if ((0.0 < *(float *)(param_1 + 0xac)) || (*(int *)(param_1 + 0xb0) != 0)) {
    local_14 = param_2 * 0.2;
    fVar3 = *(float *)(param_1 + 0xac) - param_2;
    *(float *)(param_1 + 0xac) = fVar3;
    if (fVar3 <= 0.0) {
      *(undefined4 *)(param_1 + 0xac) = 0;
    }
  }
  local_1c = `public:_long___thiscall_CGameStatusBlock::AnimateFrame(float)'::__l15::AnimateExecuter
             ::vftable;
  local_18 = local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  _DAT_00fb79e4 = &local_1c;
  piVar6 = (int *)**(int **)(param_1 + 0xc);
  if (piVar6 != *(int **)(param_1 + 0xc)) {
    do {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      *(int *)(DAT_00fb79d0 + 8 + DAT_00fb79e0 * 0xc) = piVar6[4];
      DAT_00fb79e0 = DAT_00fb79e0 + 1;
      if (DAT_00fb79e0 == DAT_00fb79ad) {
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 3;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        FUN_006ee4f0();
      }
      if (*(char *)((int)piVar6 + 0x15) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar4 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x15);
            piVar4 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(param_1 + 0xc));
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 4;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb79e0 != 0) {
    uVar7 = 0;
    if (DAT_00fb79e0 != 0) {
      do {
        SetEvent(*(HANDLE *)(DAT_00fb79b0 + uVar7 * 4));
        uVar7 = uVar7 + 1;
      } while (uVar7 < DAT_00fb79e0);
    }
    WaitForMultipleObjects(DAT_00fb79e0,DAT_00fb79c0,1,0xffffffff);
  }
  DAT_00fb79e0 = 0;
  _DAT_00fb79e4 = (undefined ***)0x0;
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_8 = 5;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_8 = 0xffffffff;
  }
  iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  if ((((iVar5 != 0) && (DAT_00fba7a4[0x1f] == 0)) &&
      ((*(uint *)(DAT_00fb1318 + 0xc01c) >> 1 & 1) == 0)) &&
     ((*(byte *)(DAT_00fb1318 + 0xc01c) & 1) == 0)) {
    FUN_004e06d0(param_1);
  }
  (**(code **)(*DAT_00fba7a4 + 0x30))(param_2);
  ExceptionList = local_10;
  return 0;
}

