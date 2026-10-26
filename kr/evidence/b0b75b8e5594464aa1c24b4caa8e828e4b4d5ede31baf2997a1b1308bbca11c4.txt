
undefined4 FUN_004afaf0(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 2) / 6;
  }
  if (uVar2 != 0) {
    puVar3 = (undefined2 *)(param_1 + 4);
    do {
      param_2 = (uint)(ushort)puVar3[-1];
      iVar1 = FUN_0040f060();
      FUN_0082ef00(&param_2);
      if ((param_1 == *(int *)(iVar1 + 0xc)) || (*(int **)(param_1 + 0x10) == (int *)0x0)) {
        FUN_006edb60("ParamUpdate: Cannot Found In CharList");
      }
      else {
        (**(code **)(**(int **)(param_1 + 0x10) + 0x2c))(*puVar3,puVar3[1]);
      }
      puVar3 = puVar3 + 3;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}

