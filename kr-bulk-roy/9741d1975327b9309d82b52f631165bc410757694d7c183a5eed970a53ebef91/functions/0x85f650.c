
undefined4 * FUN_0085f650(int param_1,undefined4 *param_2)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  bool bVar6;
  
  puVar3 = param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(param_1 + 4))[1];
  bVar6 = true;
  cVar1 = *(char *)((int)puVar5 + 0x45);
  param_2 = *(undefined4 **)(param_1 + 4);
  while (cVar1 == '\0') {
    bVar6 = *(uint *)(in_EAX + 0xc) < (uint)puVar5[3];
    if (bVar6) {
      puVar4 = (undefined4 *)*puVar5;
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
    }
    param_2 = puVar5;
    puVar5 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x45);
  }
  if (bVar6) {
    if (param_2 == (undefined4 *)**(int **)(param_1 + 4)) {
      bVar6 = true;
      goto LAB_0085f6a0;
    }
    FUN_004f9850();
  }
  if (*(uint *)(in_EAX + 0xc) <= (uint)param_2[3]) {
    piVar2 = *(int **)(in_EAX + 0x10);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(in_EAX + 0x10) = 0;
    }
    FUN_0089120c();
    *puVar3 = param_2;
    *(undefined1 *)(puVar3 + 1) = 0;
    return puVar3;
  }
LAB_0085f6a0:
  puVar5 = (undefined4 *)FUN_0085f7d0(&param_1,bVar6,in_EAX);
  *puVar3 = *puVar5;
  *(undefined1 *)(puVar3 + 1) = 1;
  return puVar3;
}

