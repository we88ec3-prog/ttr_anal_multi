
undefined4 FUN_0085aa00(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  uVar2 = 0;
  if (((*(int *)(in_EAX + 4) != 0) &&
      (iVar1 = (**(code **)(**(int **)(in_EAX + 4) + 0x28))
                         (*(int **)(in_EAX + 4),0,"WORLDBONEARRAY"), uVar2 = local_8, iVar1 != 0))
     && (iVar1 = (**(code **)(**(int **)(in_EAX + 4) + 0x4c))(*(int **)(in_EAX + 4),iVar1,"MaxBone")
        , uVar2 = local_8, iVar1 != 0)) {
    (**(code **)(**(int **)(in_EAX + 4) + 0x6c))(*(int **)(in_EAX + 4),iVar1,&local_8);
    uVar2 = local_8;
  }
  return uVar2;
}

