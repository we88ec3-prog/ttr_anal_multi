
void FUN_00649cc0(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  if (*(int *)(in_EAX + 0xf4) != 0) {
    piVar1 = *(int **)(in_EAX + 0xf4);
    iVar2 = FUN_008fed10();
    iVar3 = FUN_008fed10();
    (**(code **)(*piVar1 + 0xbc))
              (iVar2,iVar3,(piVar1[4] - piVar1[2]) + iVar2,(piVar1[5] - piVar1[3]) + iVar3);
  }
  return;
}

