
void FUN_008ccb40(undefined4 param_1)

{
  undefined4 *unaff_EBX;
  int iVar1;
  
  for (iVar1 = unaff_EBX[1]; iVar1 != 0; iVar1 = iVar1 + -1) {
    FUN_008cca40();
  }
  FUN_008b9f80(param_1,unaff_EBX[2]);
  unaff_EBX[2] = 0;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0;
  return;
}

