
void FUN_00871fc0(void)

{
  int *unaff_ESI;
  undefined4 local_24;
  
  (**(code **)(*unaff_ESI + 0x10))();
  if (local_24 == 1) {
    (**(code **)(*unaff_ESI + 0x58))();
  }
  else {
    if (local_24 == 2) {
      (**(code **)(*unaff_ESI + 0x68))();
      return;
    }
    if (local_24 == 3) {
      (**(code **)(*unaff_ESI + 0x78))();
      return;
    }
  }
  return;
}

