
void FUN_00839820(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_8 [4];
  
  if (DAT_00fbacc0 != DAT_00fbacc4) {
    if (*(int *)(in_EAX + 8) != 0) {
      uVar2 = *(undefined4 *)(in_EAX + 4);
      uVar1 = FUN_0083eef0(uVar2);
      FUN_00863050(uVar1,uVar2);
    }
    FUN_0083f0d0(&DAT_00fbacc0,local_8,DAT_00fbacc0,DAT_00fbacc4);
  }
  return;
}

