
void FUN_005968f0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *local_34;
  undefined4 local_30;
  int *local_20;
  uint local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916836;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_00753520();
  FUN_005358c0(&local_34,param_1 + 100);
  local_8 = 1;
  piVar7 = (int *)*local_34;
  local_20 = local_34;
  if (piVar7 != local_34) {
    do {
      puVar2 = *(undefined4 **)(param_2 + 4);
      piVar3 = (int *)piVar7[2];
      local_1c = piVar3[8];
      cVar1 = *(char *)((int)puVar2[1] + 0x11);
      local_14 = puVar2;
      puVar8 = (undefined4 *)puVar2[1];
      while (cVar1 == '\0') {
        if ((uint)puVar8[3] < local_1c) {
          puVar4 = (undefined4 *)puVar8[2];
          puVar8 = local_14;
        }
        else {
          puVar4 = (undefined4 *)*puVar8;
        }
        local_14 = puVar8;
        puVar8 = puVar4;
        cVar1 = *(char *)((int)puVar4 + 0x11);
      }
      if ((local_14 == *(undefined4 **)(param_2 + 4)) || (local_1c < (uint)local_14[3])) {
        local_18 = *(undefined4 **)(param_2 + 4);
        ppuVar5 = &local_18;
      }
      else {
        ppuVar5 = &local_14;
      }
      if ((*ppuVar5 == puVar2) && (((uint)piVar3[10] >> 8 & 1) != 0)) {
        uVar6 = FUN_006bde40(&local_1c);
        FUN_0044bbd0(param_1 + 0xa0,uVar6);
        (**(code **)(*piVar3 + 0x94))(0);
      }
      piVar7 = (int *)*piVar7;
    } while (piVar7 != local_20);
  }
  piVar7 = (int *)*local_34;
  *local_34 = (int)local_34;
  local_34[1] = (int)local_34;
  local_30 = 0;
  if (piVar7 != local_34) {
    do {
      piVar3 = (int *)*piVar7;
      FUN_0089120c(piVar7);
      piVar7 = piVar3;
    } while (piVar3 != local_34);
  }
  FUN_0089120c(local_34);
  ExceptionList = local_10;
  return;
}

