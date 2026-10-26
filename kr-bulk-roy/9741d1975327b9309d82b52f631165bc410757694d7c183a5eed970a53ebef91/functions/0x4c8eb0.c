
float10 FUN_004c8eb0(void)

{
  int in_EAX;
  float10 fVar1;
  
  if ((*(int *)(in_EAX + 0x15c) != 0) && (*(int *)(in_EAX + 0x370) != 0)) {
    fVar1 = (float10)FUN_007a7100();
    return fVar1;
  }
  return (float10)0;
}

