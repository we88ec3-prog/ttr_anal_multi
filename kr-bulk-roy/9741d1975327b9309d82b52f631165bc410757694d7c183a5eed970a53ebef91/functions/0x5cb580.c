
uint FUN_005cb580(HWND param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int *piVar1;
  HIMC pHVar2;
  uint uVar3;
  LPVOID pvVar4;
  undefined4 *puVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  
  pHVar2 = ImmGetContext(param_1);
  piVar1 = *(int **)(*(int *)(in_ECX + 4) + 0x14);
  if ((pHVar2 != (HIMC)0x0) && (piVar1 != (int *)0x0)) {
    if ((param_4 & 0x800) != 0) {
      uVar3 = ImmGetCompositionStringW(pHVar2,0x800,(LPVOID)0x0,0);
      uVar7 = uVar3 >> 1;
      (**(code **)(*piVar1 + 0x19c))();
      if (0 < *(int *)(in_ECX + 0x24)) {
        (**(code **)(*piVar1 + 0x198))(*(int *)(in_ECX + 0x24));
      }
      if (uVar7 != 0) {
        pvVar4 = (LPVOID)FUN_0087dc3d(uVar7 * 2);
        ImmGetCompositionStringW(pHVar2,0x800,pvVar4,uVar3);
        FUN_0043f3c0();
        FUN_00448090(0,pvVar4,uVar7);
        (**(code **)(*piVar1 + 400))(in_ECX + 8);
        FUN_00891d3d(pvVar4);
      }
      puVar5 = (undefined4 *)(in_ECX + 8);
      *(undefined4 *)(in_ECX + 0x18) = 0;
      if (7 < *(uint *)(in_ECX + 0x1c)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      *(undefined2 *)puVar5 = 0;
      *(undefined4 *)(in_ECX + 0x24) = 0;
      (**(code **)(*piVar1 + 0x1a0))();
      (**(code **)(*piVar1 + 0x1a4))();
    }
    if ((param_4 & 8) != 0) {
      (**(code **)(*piVar1 + 0x19c))();
      if (0 < *(int *)(in_ECX + 0x24)) {
        (**(code **)(*piVar1 + 0x198))(*(int *)(in_ECX + 0x24));
      }
      uVar3 = ImmGetCompositionStringW(pHVar2,8,(LPVOID)0x0,0);
      uVar7 = uVar3 >> 1;
      if (uVar7 == 0) {
        FUN_0043f3c0();
        *(undefined4 *)(in_ECX + 0x24) = 0;
      }
      else {
        pvVar4 = (LPVOID)FUN_0087dc3d(uVar7 * 2);
        ImmGetCompositionStringW(pHVar2,8,pvVar4,uVar3);
        FUN_0043f3c0();
        FUN_00448090(0,pvVar4,uVar7);
        iVar6 = (**(code **)(*piVar1 + 0x18c))(in_ECX + 8);
        *(int *)(in_ECX + 0x24) = iVar6;
        if (iVar6 != *(int *)(in_ECX + 0x18)) {
          FUN_0043f3c0();
          FUN_00448090(0,pvVar4,*(undefined4 *)(in_ECX + 0x24));
        }
        FUN_00891d3d(pvVar4);
      }
      (**(code **)(*piVar1 + 0x1a0))();
      (**(code **)(*piVar1 + 0x1a4))();
    }
    pHVar2 = (HIMC)ImmReleaseContext(param_1,pHVar2);
  }
  return (uint)pHVar2 & 0xffffff00;
}

