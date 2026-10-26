
void FUN_007d7260(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0xc) == 0) {
    (**(code **)(*unaff_ESI + 0xe4))();
    return;
  }
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  (**(code **)(*unaff_ESI + 0xe4))();
  return;
}

