
int * FUN_00761520(void)

{
  int *piVar1;
  int unaff_ESI;
  
  if (*(char *)(unaff_ESI + 0x141) != '\0') {
    FUN_006edb10("Not supported operation");
  }
  piVar1 = (int *)(unaff_ESI + 0x108);
  if (7 < *(uint *)(unaff_ESI + 0x11c)) {
    piVar1 = (int *)*piVar1;
  }
  return piVar1;
}

