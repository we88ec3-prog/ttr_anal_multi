
void FUN_00599ba0(void)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = *(int **)(in_EAX + 0x180);
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    piVar1[0x3d] = 0;
    FUN_00597040(in_EAX,*(undefined4 *)(in_EAX + 0x180),0,0);
    if ((*(uint *)(*(int *)(in_EAX + 0x180) + 0x28) >> 8 & 1) != 0) {
      FUN_0059ab90();
    }
  }
  else if (((uint)piVar1[10] >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00599bc7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0xd4))();
    return;
  }
  return;
}

