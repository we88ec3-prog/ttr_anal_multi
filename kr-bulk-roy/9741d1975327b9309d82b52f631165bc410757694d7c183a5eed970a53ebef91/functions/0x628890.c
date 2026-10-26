
void FUN_00628890(void)

{
  void *unaff_ESI;
  
  if (7 < *(uint *)((int)unaff_ESI + 0x70)) {
    FUN_0089120c(*(undefined4 *)((int)unaff_ESI + 0x5c));
  }
  *(undefined4 *)((int)unaff_ESI + 0x70) = 7;
  *(undefined4 *)((int)unaff_ESI + 0x6c) = 0;
  *(undefined2 *)((int)unaff_ESI + 0x5c) = 0;
  if (7 < *(uint *)((int)unaff_ESI + 0x54)) {
    FUN_0089120c(*(undefined4 *)((int)unaff_ESI + 0x40));
  }
  *(undefined4 *)((int)unaff_ESI + 0x54) = 7;
  *(undefined4 *)((int)unaff_ESI + 0x50) = 0;
  *(undefined2 *)((int)unaff_ESI + 0x40) = 0;
  if (*(int *)((int)unaff_ESI + 0x30) != 0) {
    FUN_0089120c(*(int *)((int)unaff_ESI + 0x30));
  }
  *(undefined4 *)((int)unaff_ESI + 0x30) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x34) = 0;
  *(undefined4 *)((int)unaff_ESI + 0x38) = 0;
  _eh_vector_destructor_iterator_(unaff_ESI,0x10,3,FUN_00418290);
  return;
}

