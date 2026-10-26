
void FUN_005359f0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_3 != param_4) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    puVar3 = param_3;
    for (; param_4 != puVar1; param_4 = (undefined4 *)((int)param_4 + 0x1f)) {
      puVar4 = param_4;
      puVar5 = puVar3;
      for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(undefined2 *)puVar5 = *(undefined2 *)puVar4;
      puVar3 = (undefined4 *)((int)puVar3 + 0x1f);
      *(undefined1 *)((int)puVar5 + 2) = *(undefined1 *)((int)puVar4 + 2);
    }
    *(undefined4 **)(param_1 + 4) = puVar3;
  }
  *param_2 = param_3;
  return;
}

