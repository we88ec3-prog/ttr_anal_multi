
void FUN_00867730(void)

{
  int in_EAX;
  int unaff_ESI;
  
  if (unaff_ESI != in_EAX) {
    if (*(int *)(unaff_ESI + 4) == 0) {
      *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(in_EAX + 4);
    }
    FUN_00867fd0(unaff_ESI,in_EAX);
  }
  return;
}

