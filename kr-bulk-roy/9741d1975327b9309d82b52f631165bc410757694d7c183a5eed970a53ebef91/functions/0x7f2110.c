
/* WARNING: Removing unreachable block (ram,0x007f2175) */

void FUN_007f2110(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x88) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0x88) + 0x44))(), iVar1 == 0)) {
    iVar1 = *(int *)(in_ECX + 0x88);
    if (*(int **)(iVar1 + 0x54) != (int *)0x0) {
      (**(code **)(**(int **)(iVar1 + 0x54) + 0x5c))(iVar1);
    }
    *(undefined4 *)(iVar1 + 0x54) = 0;
    *(undefined4 *)(iVar1 + 0x5c) = 0;
  }
  if (*(undefined4 **)(in_ECX + 0x88) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x88))(1);
    *(undefined4 *)(in_ECX + 0x88) = 0;
  }
  if (*(int *)(in_ECX + 0x8c) != *(int *)(in_ECX + 0x90)) {
    *(int *)(in_ECX + 0x90) = *(int *)(in_ECX + 0x8c);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}

