
undefined4 FUN_0085aaf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (((*(int *)(param_1 + 4) != 0) && (param_2 != 0)) && (in_EAX != 0)) {
    iVar1 = *(int *)(in_EAX + 0x188);
    for (iVar6 = *(int *)(in_EAX + 0x184); iVar6 != iVar1; iVar6 = iVar6 + 0x10) {
      uVar2 = *(undefined4 *)(iVar6 + 0xc);
      if (*(int *)(iVar6 + 4) == 0xb) {
        puVar4 = (undefined4 *)FUN_0083b440();
        if (puVar4 == (undefined4 *)0x0) {
          (**(code **)(**(int **)(param_1 + 4) + 0xd0))(*(int **)(param_1 + 4),uVar2,0);
        }
        else {
          (**(code **)(**(int **)(param_1 + 4) + 0xd0))(*(int **)(param_1 + 4),uVar2,*puVar4);
        }
      }
      else {
        iVar3 = **(int **)(param_1 + 4);
        uVar5 = FUN_008676a0();
        (**(code **)(iVar3 + 0x50))
                  (*(undefined4 *)(param_1 + 4),uVar2,*(undefined4 *)(iVar6 + 8),uVar5);
      }
    }
    return 1;
  }
  return 0;
}

