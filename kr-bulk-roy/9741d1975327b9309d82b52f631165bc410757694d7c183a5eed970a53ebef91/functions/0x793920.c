
float10 FUN_00793920(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  if (param_2 <= param_1) {
    iVar1 = (**(code **)(*unaff_ESI + 4))(local_c);
    piVar2 = (int *)(**(code **)(*unaff_ESI + 4))(local_14);
    iVar1 = *(int *)(iVar1 + 4);
    iVar5 = *piVar2;
    iVar3 = (**(code **)(*unaff_ESI + 0x20))(param_1);
    iVar4 = (**(code **)(*unaff_ESI + 0x20))(param_2);
    return (float10)(iVar4 + ((iVar1 - iVar5) - iVar3));
  }
  iVar1 = (**(code **)(*unaff_ESI + 0x20))(param_1);
  iVar5 = (**(code **)(*unaff_ESI + 0x20))(param_2);
  return (float10)(iVar5 - iVar1);
}

