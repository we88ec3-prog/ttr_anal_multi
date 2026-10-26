
void FUN_00767b30(void)

{
  int in_EAX;
  int *piVar1;
  undefined1 local_8 [4];
  
  if ((*(int **)(in_EAX + 0xf4) != (int *)0x0) &&
     (*(uint *)(in_EAX + 0x13c) < (uint)(*(int *)(in_EAX + 0x114) - *(int *)(in_EAX + 0x110) >> 2)))
  {
    piVar1 = *(int **)(*(int *)(in_EAX + 0x110) + *(uint *)(in_EAX + 0x13c) * 4);
    if (7 < (uint)piVar1[5]) {
      piVar1 = (int *)*piVar1;
    }
    (**(code **)(**(int **)(in_EAX + 0xf4) + 0x30))
              (in_EAX + 0x144,local_8,piVar1,*(undefined4 *)(in_EAX + 0x140));
    return;
  }
  *(undefined4 *)(in_EAX + 0x144) = 0;
  return;
}

