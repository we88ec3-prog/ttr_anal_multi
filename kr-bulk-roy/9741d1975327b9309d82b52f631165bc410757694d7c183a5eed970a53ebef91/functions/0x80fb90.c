
undefined4 FUN_0080fb90(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  FUN_00810d90();
  uVar1 = alcGetCurrentContext();
  uVar2 = alcGetContextsDevice(uVar1);
  alcMakeContextCurrent(0);
  alcDestroyContext(uVar1);
  alcCloseDevice(uVar2);
  return 1;
}

