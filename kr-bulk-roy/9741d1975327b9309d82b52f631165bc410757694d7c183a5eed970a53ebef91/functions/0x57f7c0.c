
void FUN_0057f7c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0x1e] != 0) {
    (**(code **)(*(int *)(unaff_ESI[2] + 8) + 4))();
    (**(code **)(*(int *)(unaff_ESI[3] + 8) + 4))();
    puVar1 = (undefined4 *)unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[2] + 0x10))();
    FUN_0057fde0(*puVar1,"IS3D_BookRTTexture00");
    puVar1 = (undefined4 *)unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[3] + 0x10))();
    FUN_0057fde0(*puVar1,"IS3D_BookRTTexture01");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[2] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 4),"IS3D_BookRTTexture10");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[3] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 4),"IS3D_BookRTTexture11");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[2] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 8),"IS3D_BookRTTexture20");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[3] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 8),"IS3D_BookRTTexture21");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[2] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 0xc),"IS3D_BookRTTexture30");
    iVar2 = unaff_ESI[0xd];
    (**(code **)(*(int *)unaff_ESI[3] + 0x10))();
    FUN_0057fde0(*(undefined4 *)(iVar2 + 0xc),"IS3D_BookRTTexture31");
    (**(code **)(*(int *)*unaff_ESI + 0x114))((int *)*unaff_ESI,0,8,0xbf000000);
    unaff_ESI[0x1f] = 1;
  }
  return;
}

