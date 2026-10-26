
void FUN_00609cb0(void)

{
  int unaff_EDI;
  undefined4 local_8;
  
  if ((*(int *)(unaff_EDI + 0x110) == -1) || (*(int *)(unaff_EDI + 0x114) == -1)) {
    (**(code **)(**(int **)(unaff_EDI + 0xf8) + 0x19c))(0xffffffff,0xffffffff,0,0);
    FUN_00757710();
  }
  else {
    (**(code **)(**(int **)(unaff_EDI + 0xf8) + 0x19c))
              (*(undefined4 *)(unaff_EDI + 0x110),*(undefined4 *)(unaff_EDI + 0x114),
               *(undefined4 *)(unaff_EDI + 0x118),*(undefined4 *)(unaff_EDI + 0x11c));
    FUN_00757800(unaff_EDI + 0x120);
  }
  (**(code **)(**(int **)(unaff_EDI + 0xf8) + 200))();
  (**(code **)(**(int **)(unaff_EDI + 0xfc) + 200))();
  local_8 = 0;
  if ((*(int *)(unaff_EDI + 0x110) != -1) && (*(int *)(unaff_EDI + 0x114) != -1)) {
    local_8 = 1;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x100) + 0x90))(local_8);
  (**(code **)(**(int **)(unaff_EDI + 0x100) + 200))();
  return;
}

