
void FUN_00753780(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(in_EAX + 0x13c4) != 0) {
    uVar1 = FUN_008fed10();
    uVar2 = FUN_008fed10();
    (**(code **)(**(int **)(in_EAX + 0x13c4) + 0xbc))(0,0,uVar1,uVar2);
  }
  return;
}

