
void FUN_007591a0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  undefined4 local_10;
  
  if (*(int *)(in_EAX + 0x20) != 0) {
    puVar2 = (undefined4 *)**(undefined4 **)(in_EAX + 0x1c);
    local_10 = 0xffffff;
    for (; (puVar2 != *(undefined4 **)(in_EAX + 0x1c) && ((int)puVar2[2] <= param_1 + param_2));
        puVar2 = (undefined4 *)*puVar2) {
      local_10 = puVar2[3];
    }
    FUN_00759130(param_1,param_2,0);
    FUN_00759060(param_3,0);
    if ((uint)(param_1 + param_2) <= *(uint *)(in_EAX + 0x10)) {
      FUN_00759060(local_10,1);
    }
    FUN_007592c0(in_EAX);
    return;
  }
  iVar1 = *(int *)(in_EAX + 0x1c);
  iVar3 = FUN_00404fd0(iVar1,*(undefined4 *)(iVar1 + 4));
  if (*(int *)(in_EAX + 0x20) != 0x1ffffffe) {
    *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + 1;
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    iVar1 = *(int *)(in_EAX + 0x1c);
    iVar3 = FUN_00404fd0(iVar1,*(undefined4 *)(iVar1 + 4));
    if (*(int *)(in_EAX + 0x20) != 0x1ffffffe) {
      *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + 1;
      *(int *)(iVar1 + 4) = iVar3;
      **(int **)(iVar3 + 4) = iVar3;
      return;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

