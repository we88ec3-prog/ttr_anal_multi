
int FUN_008e9260(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 local_c [8];
  
  iVar3 = FUN_008e9120();
  if ((iVar3 == 0) && (iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x80), *(int *)(iVar1 + 0x30) != 0))
  {
    piVar2 = *(int **)(iVar1 + 0x30);
    (**(code **)(*piVar2 + 4))(piVar2[1],local_c);
  }
  return iVar3;
}

