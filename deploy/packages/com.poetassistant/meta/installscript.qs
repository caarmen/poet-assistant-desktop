function Component() {
}
Component.prototype.createOperations = function()
{
    component.createOperations();
    if (systemInfo.productType === "windows") {
        component.addOperation("CreateShortcut", "@TargetDir@/PoetAssistant.exe", "@StartMenuDir@/Poet Assistant.lnk",
            "workingDirectory=@TargetDir@", "iconPath=@TargetDir@/icon.ico",
            "iconId=0", "description=Poet Assistant");
    }
}
