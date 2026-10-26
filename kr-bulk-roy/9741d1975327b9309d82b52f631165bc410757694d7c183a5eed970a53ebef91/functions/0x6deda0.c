
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006deda0(void)

{
  char cVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x34) == 0) {
    cVar1 = FUN_006ea3d0();
    if (cVar1 == '\0') {
      FUN_006e71f0(1,1);
      FUN_006e2e20();
      FUN_006e71f0(0,0);
      _DAT_00fba7c8 = 1;
    }
  }
  (**(code **)(**(int **)(unaff_ESI + 0x10) + 0x50))(*(int **)(unaff_ESI + 0x10),1);
  return;
}

