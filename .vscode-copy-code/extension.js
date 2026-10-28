const vscode = require('vscode');

function activate(context) {
  const disposable = vscode.commands.registerCommand('copyActiveEditorCode.copy', async () => {
    const editor = vscode.window.activeTextEditor;
    if (!editor) {
      vscode.window.showWarningMessage('コピーするエディタがありません。');
      return;
    }

    await vscode.env.clipboard.writeText(editor.document.getText());
    vscode.window.setStatusBarMessage('エディタ全体をコピーしました', 2000);
  });

  context.subscriptions.push(disposable);
}

function deactivate() {}

module.exports = { activate, deactivate };
