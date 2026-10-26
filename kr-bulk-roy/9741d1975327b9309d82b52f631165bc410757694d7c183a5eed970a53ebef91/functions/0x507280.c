
undefined4 FUN_00507280(int param_1)

{
  undefined4 *puVar1;
  uintptr_t *puVar2;
  uintptr_t uVar3;
  
  if ((*(int *)(param_1 + 0x20) == 0) &&
     (puVar1 = *(undefined4 **)(param_1 + 0x10), puVar1 != *(undefined4 **)(param_1 + 0x14))) {
    do {
      (**(code **)(*(int *)*puVar1 + 4))();
      puVar1 = puVar1 + 1;
    } while (puVar1 != *(undefined4 **)(param_1 + 0x14));
  }
  puVar1 = (undefined4 *)FUN_00891268(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = FunctorArg0Inst<void,CDataMgr>::vftable;
    puVar1[1] = param_1;
    puVar1[2] = &LAB_00507380;
  }
  puVar2 = (uintptr_t *)FUN_00891268(0xc);
  if (puVar2 == (uintptr_t *)0x0) {
    puVar2 = (uintptr_t *)0x0;
  }
  else {
    *puVar2 = 0xffffffff;
    puVar2[1] = 0;
    puVar2[2] = 0;
  }
  puVar2[2] = (uintptr_t)puVar1;
  uVar3 = __beginthreadex((void *)0x0,0,FUN_004fb740,puVar1,0,puVar2 + 1);
  *puVar2 = uVar3;
  if (uVar3 != 0xffffffff) {
    *(uintptr_t **)(param_1 + 0x24) = puVar2;
    return 1;
  }
  FUN_0089120c(puVar2);
  *(undefined4 *)(param_1 + 0x24) = 0;
  return 1;
}

