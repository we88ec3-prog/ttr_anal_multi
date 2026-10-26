
/* WARNING: Removing unreachable block (ram,0x0072711d) */
/* WARNING: Removing unreachable block (ram,0x007270d8) */
/* WARNING: Removing unreachable block (ram,0x00727163) */

void FUN_007270b0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *in_EAX;
  uint *unaff_ESI;
  bool bVar3;
  
  uVar1 = unaff_ESI[1];
  if (in_EAX[1] == 0) {
    if (uVar1 == 0) {
      bVar3 = *in_EAX < *unaff_ESI;
      goto LAB_007270e4;
    }
  }
  else {
    if (uVar1 != 0) {
      bVar3 = in_EAX[1] < uVar1;
LAB_007270e4:
      if (!bVar3) goto LAB_007270ff;
    }
    uVar1 = *in_EAX;
    uVar2 = in_EAX[1];
    *in_EAX = *unaff_ESI;
    in_EAX[1] = unaff_ESI[1];
    *unaff_ESI = uVar1;
    unaff_ESI[1] = uVar2;
  }
LAB_007270ff:
  uVar1 = param_1[1];
  uVar2 = in_EAX[1];
  if (uVar1 == 0) {
    if (uVar2 == 0) {
      bVar3 = *param_1 < *in_EAX;
      goto LAB_0072712d;
    }
  }
  else {
    if (uVar2 != 0) {
      bVar3 = uVar1 < uVar2;
LAB_0072712d:
      if (!bVar3) goto LAB_00727145;
    }
    uVar2 = *param_1;
    *param_1 = *in_EAX;
    param_1[1] = in_EAX[1];
    *in_EAX = uVar2;
    in_EAX[1] = uVar1;
  }
LAB_00727145:
  uVar1 = in_EAX[1];
  uVar2 = unaff_ESI[1];
  if (uVar1 == 0) {
    if (uVar2 != 0) {
      return;
    }
    bVar3 = *in_EAX < *unaff_ESI;
  }
  else {
    if (uVar2 == 0) goto LAB_0072717a;
    bVar3 = uVar1 < uVar2;
  }
  if (!bVar3) {
    return;
  }
LAB_0072717a:
  uVar2 = *in_EAX;
  *in_EAX = *unaff_ESI;
  in_EAX[1] = unaff_ESI[1];
  *unaff_ESI = uVar2;
  unaff_ESI[1] = uVar1;
  return;
}

