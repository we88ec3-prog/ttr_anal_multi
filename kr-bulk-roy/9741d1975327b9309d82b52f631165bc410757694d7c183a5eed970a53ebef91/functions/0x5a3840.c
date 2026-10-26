
int * FUN_005a3840(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_EAX;
  undefined4 uVar4;
  int *piVar5;
  int *in_ECX;
  undefined4 *extraout_EDX;
  
  uVar4 = (**(code **)(*in_ECX + 0x18))();
  *(undefined4 *)(in_EAX + 0x24) = uVar4;
  if ((*(int *)(in_EAX + 0x3c) != 0) && ((*(uint *)(in_EAX + 0x28) & 0x40000) == 0)) {
    FUN_007486f0(uVar4);
  }
  puVar1 = *(undefined4 **)(in_EAX + 100);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    FUN_007486f0(*(undefined4 *)(in_EAX + 0x24));
    puVar2 = (undefined4 *)*extraout_EDX;
  }
  *param_2 = in_EAX;
  piVar5 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar3 = *piVar5;
  uVar4 = (**(code **)(*in_ECX + 0x1c))(param_1,in_ECX + 1);
  piVar5 = (int *)(**(code **)(iVar3 + 0x28))(param_1,*param_2,uVar4);
  if (piVar5 != (int *)0x0) {
    if ((piVar5[10] & 1U) != 0) {
      piVar5[10] = piVar5[10] ^ 1;
    }
    (**(code **)(*piVar5 + 0x94))(0);
  }
  return piVar5;
}

