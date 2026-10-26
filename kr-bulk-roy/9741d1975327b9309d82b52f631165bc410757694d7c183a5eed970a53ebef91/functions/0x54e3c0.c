
int * FUN_0054e3c0(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093af74;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  uVar2 = DAT_00fb73b8 & 1;
  puVar5 = (undefined4 *)(DAT_00fb76e8 + 0xc);
  puVar6 = (undefined4 *)(in_ECX + 0xc);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  if (uVar2 == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  local_24 = *(undefined4 *)(in_ECX + 4);
  FUN_0082ef00(&local_24);
  piVar3 = local_20;
  if ((local_20 != DAT_00fb73dc) && (piVar3 = (int *)0x0, local_20[4] != 0)) {
    FUN_0049c3d0();
    piVar3 = local_20;
    if (local_20 == (int *)0x0) {
      local_c = 0xffffffff;
      if (local_1c != (int *)0x0) {
        piVar1 = local_1c + 1;
        LOCK();
        iVar4 = *piVar1;
        piVar3 = (int *)*piVar1;
        *piVar1 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          piVar3 = (int *)(**(code **)*local_1c)();
          LOCK();
          iVar4 = local_1c[2] + -1;
          local_1c[2] = iVar4;
          UNLOCK();
          if (iVar4 == 0) {
            piVar3 = (int *)(**(code **)(*local_1c + 4))();
            ExceptionList = local_14;
            return piVar3;
          }
        }
      }
    }
    else {
      if (local_20[7] != 0) {
        piVar3 = (int *)FUN_007d32d0(in_ECX + 8,"CAMERA_DUMMY01");
        if (piVar3 != (int *)0x0) {
          *(undefined4 *)(in_ECX + 0x38) = 0;
        }
      }
      local_c = 0xffffffff;
      if (local_1c != (int *)0x0) {
        LOCK();
        iVar4 = local_1c[1] + -1;
        local_1c[1] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)*local_1c)();
          piVar3 = local_1c + 2;
          LOCK();
          iVar4 = *piVar3;
          *piVar3 = iVar4 + -1;
          UNLOCK();
          if (iVar4 + -1 == 0) {
            piVar3 = (int *)(**(code **)(*local_1c + 4))();
          }
        }
      }
    }
  }
  ExceptionList = local_14;
  return piVar3;
}

