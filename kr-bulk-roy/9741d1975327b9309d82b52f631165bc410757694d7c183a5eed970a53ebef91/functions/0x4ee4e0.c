
void FUN_004ee4e0(undefined4 *param_1,code *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  cVar4 = (*param_2)();
  if (cVar4 != '\0') {
    uVar1 = unaff_ESI[2];
    uVar2 = *unaff_ESI;
    uVar3 = unaff_ESI[1];
    *unaff_ESI = *unaff_EDI;
    unaff_ESI[1] = unaff_EDI[1];
    unaff_ESI[2] = unaff_EDI[2];
    *unaff_EDI = uVar2;
    unaff_EDI[1] = uVar3;
    unaff_EDI[2] = uVar1;
  }
  cVar4 = (*param_2)(param_1);
  if (cVar4 != '\0') {
    uVar1 = param_1[2];
    uVar2 = *param_1;
    uVar3 = param_1[1];
    *param_1 = *unaff_ESI;
    param_1[1] = unaff_ESI[1];
    param_1[2] = unaff_ESI[2];
    *unaff_ESI = uVar2;
    unaff_ESI[1] = uVar3;
    unaff_ESI[2] = uVar1;
  }
  cVar4 = (*param_2)();
  if (cVar4 != '\0') {
    uVar1 = *unaff_ESI;
    uVar2 = unaff_ESI[1];
    uVar3 = unaff_ESI[2];
    *unaff_ESI = *unaff_EDI;
    unaff_ESI[1] = unaff_EDI[1];
    unaff_ESI[2] = unaff_EDI[2];
    *unaff_EDI = uVar1;
    unaff_EDI[1] = uVar2;
    unaff_EDI[2] = uVar3;
  }
  return;
}

