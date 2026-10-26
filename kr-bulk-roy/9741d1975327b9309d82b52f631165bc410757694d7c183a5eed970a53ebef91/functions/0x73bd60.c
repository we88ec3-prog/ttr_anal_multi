
void FUN_0073bd60(uint param_1)

{
  int iVar1;
  int iVar2;
  HDC hdc;
  int in_EAX;
  HGDIOBJ pvVar3;
  undefined4 *unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 0x1c);
  iVar2 = *(int *)(in_EAX + 0x18);
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  if ((param_1 < (uint)(iVar1 - iVar2 >> 2)) &&
     (iVar1 = *(int *)(*(int *)(in_EAX + 0x18) + param_1 * 4), iVar1 != 0)) {
    pvVar3 = *(HGDIOBJ *)(iVar1 + 0xac);
    hdc = *(HDC *)(in_EAX + 0xc);
    *unaff_ESI = hdc;
    pvVar3 = SelectObject(hdc,pvVar3);
    unaff_ESI[1] = pvVar3;
    return;
  }
  *unaff_ESI = *(undefined4 *)(in_EAX + 0xc);
  pvVar3 = GetStockObject(0xd);
  pvVar3 = SelectObject(*(HDC *)(in_EAX + 0xc),pvVar3);
  unaff_ESI[1] = pvVar3;
  return;
}

