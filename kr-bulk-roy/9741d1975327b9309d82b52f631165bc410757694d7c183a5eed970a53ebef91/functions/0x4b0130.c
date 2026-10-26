
undefined4 FUN_004b0130(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 2) / 3;
  }
  if (uVar2 != 0) {
    puVar3 = (ushort *)(param_1 + 2);
    do {
      param_2 = (uint)*puVar3;
      iVar1 = FUN_0040f060();
      FUN_0082ef00(&param_2);
      if ((param_1 == *(int *)(iVar1 + 0xc)) || (*(int *)(param_1 + 0x10) == 0)) {
        FUN_006edb60("Motion Update: Cannot Found In CharList");
      }
      else {
        (**(code **)(*(int *)(*(int *)(param_1 + 0x10) + 0xf0) + 8))((int)(char)puVar3[1]);
      }
      puVar3 = (ushort *)((int)puVar3 + 3);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}

